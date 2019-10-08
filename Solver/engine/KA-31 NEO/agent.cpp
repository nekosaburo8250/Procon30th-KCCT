#include "agent.hpp"
#include <process.h>


namespace solver::engine::ka31neo
{
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
			throw L"solver::engine::ka31neo::Agent : �X���b�h�̍쐬�Ɏ��s���܂���";
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