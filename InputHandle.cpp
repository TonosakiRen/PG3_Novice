#include "InputHandle.h"
#include "Command.h"
#include "KeyInput.h"
#include "Novice.h"

Command* InputHandle::HandleInput()
{
	if (KeyInput::IsTrigger(DIK_W)) {
			return triggerKeyW_;
	}
	if (KeyInput::IsTrigger(DIK_A)) {
		return triggerKeyA_;
	}
	if (KeyInput::IsTrigger(DIK_S)) {
		return triggerKeyS_;
	}
	if (KeyInput::IsTrigger(DIK_D)) {
		return triggerKeyD_;
	}
	return nullptr;
}

void InputHandle::AssignMoveLeftCommandToTriggerKeyA()
{
	Command* command = new MoveLeftCommand();
	this->triggerKeyA_ = command;
}

void InputHandle::AssignMoveRightCommandToTriggerKeyD()
{
	Command* command = new MoveRightCommand();
	this->triggerKeyD_ = command;
}

void InputHandle::AssignMoveUpCommandToTriggerKeyW()
{
	Command* command = new MoveUpCommand();
	this->triggerKeyW_ = command;
}

void InputHandle::AssignMoveDownCommandToTriggerKeyS()
{
	Command* command = new MoveDownCommand();
	this->triggerKeyS_ = command;
}
