#pragma once
class Command;
class InputHandle
{
public:
	Command* HandleInput();

	void AssignMoveLeftCommandToTriggerKeyA();
	void AssignMoveRightCommandToTriggerKeyD();
	void AssignMoveUpCommandToTriggerKeyW();
	void AssignMoveDownCommandToTriggerKeyS();
private:
	Command* triggerKeyA_;
	Command* triggerKeyD_;
	Command* triggerKeyW_;
	Command* triggerKeyS_;

};

