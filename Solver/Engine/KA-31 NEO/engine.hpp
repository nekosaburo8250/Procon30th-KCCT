#pragma once

#include "../interface.hpp"
#include "agent.hpp"
#include <vector>


namespace solver::engine::ka31neo
{
	class Engine : public Interface
	{
		TeamID team;
		unsigned numRemainingTurns;
		std::vector<Agent> agents;
		Command agentIntentions;

	public:
		void initialize(TeamID team, const simulator::Stage &stage);
		void startThinking()override;
		void stopThinking()override;
		Command getBestActions()const override;
	};
}