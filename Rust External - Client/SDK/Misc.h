#pragma once

void Misc(UINT64 TodCycle)
{
	if (Value::bools::Visuals::World::AlwaysDay)
		safe_write(TodCycle + 0x10, Value::floats::Visuals::World::Time, float);

	if (Value::bools::Player::PlayerWalk::Spiderman)
		LocalPlayer.BasePlayer->SpiderMan();

	if (Value::bools::Player::PlayerWalk::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin();


	if (Value::floats::Player::LongNeck && GetAsyncKeyState(Value::floats::Player::LongNeckKey)) {
		
		LocalPlayer.BasePlayer->LongNeck();
	}

	if (Value::bools::Player::PlayerWalk::MinicopterFire) 
		LocalPlayer.BasePlayer->MinicopterShooting();


	if (Value::bools::Misc::FlyHack)  
		LocalPlayer.BasePlayer->FlyHack();

	if (Value::bools::Player::PlayerWalk::nightmode)
		LocalPlayer.BasePlayer->NightMode();

	if (Value::bools::Misc::SpeedHack)
		LocalPlayer.BasePlayer->SpeedHack();

	

	if (Value::bools::Misc::DebugCamera)
		LocalPlayer.BasePlayer->FixCamera();

	if (Value::bools::Player::PlayerWalk::ChangeGravity)
		LocalPlayer.BasePlayer->GravituMod();

	if (Value::bools::Player::PlayerWalk::InfinityJump)
		LocalPlayer.BasePlayer->InfinityJump();

	if (Value::bools::Player::CustomFov)
		LocalPlayer.BasePlayer->SetFov();

	if (Value::bools::Player::Zoom)
		LocalPlayer.BasePlayer->Zoom();

	

}