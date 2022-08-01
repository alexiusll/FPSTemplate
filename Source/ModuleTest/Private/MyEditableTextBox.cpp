// Fill out your copyright notice in the Description page of Project Settings.

#include "MyEditableTextBox.h"
#include "SlateCore\Private\Fonts\FontCacheFreeType.h"
#include "Core\Public\Internationalization\IBreakIterator.h"
#include "Core\Public\Internationalization\BreakIterator.h"
#include "SlateCore\Private\Fonts\FontCacheCompositeFont.h"
#include "Core\Public\Misc\FileHelper.h"

#include "Slate\Public\Widgets\Input\SEditableTextBox.h"
#include "Slate\Public\Framework\Text\ShapedTextCache.h"

#include "Core\Public\Internationalization\IBreakIterator.h"

// 编辑前的预处理
FText preChangeText(FText InText, FSlateFontInfo InFont) {
	FFontData fontData = InFont.GetCompositeFont()->DefaultTypeface.Fonts[0].Font;
	FString filename = fontData.GetFontFilename();
	FFontFaceDataConstPtr FontFaceData = fontData.GetFontFaceData();

	UE_LOG(LogTemp, Warning, TEXT("font name :%s"), *filename);

	// FT_Library  library;   /* handle to library     */
	// FT_Face     face;      /* handle to face object */

	// FT_Error error = FT_Init_FreeType(&library);
	// error = FT_New_Memory_Face(library, FontFaceData->GetData().GetData(), static_cast<FT_Long>(FontFaceData->GetData().Num()), fontData.GetSubFaceIndex(), &face);

	//if (error) {
	//	return InText.FromString(TEXT("font error"));
	//}

	// int32 index = FT_Get_Char_Index(face,TEXT('?'));
	// UE_LOG(LogTemp, Warning, TEXT("? index :%d"), index);

	TSharedRef<FSlateFontCache> FontCache = FSlateApplication::Get().GetRenderer()->GetFontCache();

	FString str = InText.ToString();
	FString newStr;
	int32 RunningTextIndex = 0;
	TSharedRef<IBreakIterator> GraphemeBreakIterator = FBreakIterator::CreateCharacterBoundaryIterator();
	GraphemeBreakIterator->SetString(*str, str.Len()); // 用于检测字母簇边界的迭代器

	for (int32 PreviousBreak = 0, CurrentBreak = 0; (CurrentBreak = GraphemeBreakIterator->MoveToNext()) != INDEX_NONE; PreviousBreak = CurrentBreak)
	{
		const int32 ClusterSize = CurrentBreak - PreviousBreak;
		// Combine any surrogate pairs into a complete codepoint
		// 将任何代理对组合成一个完整的 codepoint
		UTF32CHAR CurrentCodepoint = str[RunningTextIndex];
#if !PLATFORM_TCHAR_IS_4_BYTES
		if (ClusterSize > 1)
		{
			const int32 NextTextIndex = RunningTextIndex + 1;
			if (StringConv::IsHighSurrogate(str[RunningTextIndex]) && StringConv::IsLowSurrogate(str[NextTextIndex]))
			{
				CurrentCodepoint = StringConv::EncodeSurrogate(str[RunningTextIndex], str[NextTextIndex]);
				if (FontCache->CanLoadCodepoint(fontData, CurrentCodepoint)) {
					newStr += str[RunningTextIndex];
					newStr += str[NextTextIndex];
				}
				else {
					UE_LOG(LogTemp, Warning, TEXT("ClusterSize>1 char code :%d"), CurrentCodepoint);
				}
			}
		}
#endif	// !PLATFORM_TCHAR_IS_4_BYTES
		if (ClusterSize == 1) {
			if (FontCache->CanLoadCodepoint(fontData, CurrentCodepoint)) {
				newStr += str[RunningTextIndex];
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("char code :%d"), str[RunningTextIndex]);
			}
		}

		RunningTextIndex += ClusterSize;
	}

	//for (int32 index = 0; index < str.Len(); index++) {
	//	if (FT_Get_Char_Index(face, str[index]) != 0) {
	//		newStr += str[index];
	//	}
	//	else {
	//		UE_LOG(LogTemp, Warning, TEXT("char code :%d"), str[index]);
	//	}
	//}

	return InText.FromString(newStr);
}

void UMyEditableTextBox::HandleOnTextChanged(const FText& InText) {
	// 执行预处理
    FText newText = InText;

	if (!InText.EqualTo(Text))
	{
		newText = preChangeText(InText, WidgetStyle.Font);

		SetText(newText);
	}
	
	OnTextChanged.Broadcast(newText);
}

