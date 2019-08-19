#include "MatchGameUtil.h"

MatchGameUtil* MatchGameUtil::instance = 0;

MatchGameUtil::MatchGameUtil()
{

}

MatchGameUtil::~MatchGameUtil()
{

}

MatchGameUtil* MatchGameUtil::Instance()
{
	if (!instance)
	{
		return instance = new MatchGameUtil();
	}
	return instance;
}

void MatchGameUtil::Reset()
{
	delete instance;
	instance = 0;
}

ENDSTATE MatchGameUtil::GetEndState()
{
	return endState;
}

void MatchGameUtil::SetEndState(ENDSTATE endstate)
{
	endState = endstate;
}