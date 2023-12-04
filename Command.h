#pragma once
class Select;
class Command
{
public:
	virtual ~Command();
	virtual void Exec(Select* select) = 0;
};

class MoveRightCommand : public Command {
public:
	void Exec(Select* select) override;
};

class MoveLeftCommand : public Command {
public:
	void Exec(Select* select) override;
};

class MoveUpCommand : public Command {
public:
	void Exec(Select* select) override;
};

class MoveDownCommand : public Command {
public:
	void Exec(Select* select) override;
};