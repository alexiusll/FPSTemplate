--[[
Author: linkenzone
Date: 2022-07-08 20:35:47
Descripttion: Do not edit
--]]
--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local Screen = require "Tutorials.Screen"

local FirstLuaActor = Class()

function FirstLuaActor:Initialize(Initializer)
    local msg = [[hello world lua!]]
    print(msg)
    Screen.print(msg)
end

--function FirstLuaActor:UserConstructionScript()
--end

--function FirstLuaActor:ReceiveBeginPlay()
--end

--function FirstLuaActor:ReceiveEndPlay()
--end

-- function FirstLuaActor:ReceiveTick(DeltaSeconds)
-- end

--function FirstLuaActor:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function FirstLuaActor:ReceiveActorBeginOverlap(OtherActor)
--end

--function FirstLuaActor:ReceiveActorEndOverlap(OtherActor)
--end

return FirstLuaActor
