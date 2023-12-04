#include "Command.h"
#include "Select.h"

void MoveRightCommand::Exec(Select* select)
{
	select->MoveRight();
}

void MoveLeftCommand::Exec(Select* select)
{
	select->MoveLeft();
}

void MoveUpCommand::Exec(Select* select)
{
	select->MoveUp();
}

void MoveDownCommand::Exec(Select* select)
{
	select->MoveDown();
}

Command::~Command()
{
}
