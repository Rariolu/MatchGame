#ifndef _MATCHGAMEUTIL_H
#define _MATCHGAMEUTIL_H

enum ENDSTATE
{
	WIN,
	LOSE
};

class MatchGameUtil
{
	public:
		static MatchGameUtil* Instance();
		static void Reset();
		ENDSTATE GetEndState();
		void SetEndState(ENDSTATE endstate);
	private:
		MatchGameUtil();
		~MatchGameUtil();
		static MatchGameUtil* instance;
		ENDSTATE endState;
};

#endif