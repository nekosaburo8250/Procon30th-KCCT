#include "agent.hpp"
#include <process.h>


namespace solver::engine::ka31neo
{
	unsigned __stdcall Agent::startThinking(void *arg)
	{
		Agent &agent = *reinterpret_cast<Agent *>(arg);
		while(agent.isThinking)
		{
			agent.currentNode->search();
		}
		return 0;
	}

	Agent::Agent(TeamID team_id, uint8_t agentNo, const StageInterface &stage)
		: isThinking(false), threadHandle(NULL), threadID(0)
	{
		currentNode = new Node(Simulator(team_id, agentNo, stage));
	}

	void Agent::startThinking()
	{
		isThinking = true;
		threadHandle = reinterpret_cast<HANDLE>(_beginthreadex(NULL, 0, startThinking, this, 0, &threadID));
		if(threadHandle == NULL)
		{
			throw L"solver::engine::ka31neo::Agent : スレッドの作成に失敗しました";
		}
	}

	void Agent::stopThinking()
	{
		isThinking = false;
		WaitForSingleObject(threadHandle, INFINITE);
		CloseHandle(threadHandle);
	}

	ActionID Agent::getBestAction()const noexcept
	{
		return currentNode->getBestAction();
	}
}