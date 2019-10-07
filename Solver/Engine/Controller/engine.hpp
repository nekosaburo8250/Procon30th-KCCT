#pragma once

#include "../interface.hpp"


namespace solver::engine::controller
{
	class Engine : public Interface
	{
		TeamID team;
		unsigned numAgents;
		unsigned numRemainingTurns;
		const simulator::Stage *stage;
		Command agentIntentions;

	public:
		Engine()
		{
			team = TeamID::null;
			numAgents = 0;
			numRemainingTurns = 0;
			stage = nullptr;
		}
		void initialize(TeamID team, const simulator::Stage &stage);
		void startThinking()override;
		void stopThinking()override;
		Command getBestActions()const override;
	};
}