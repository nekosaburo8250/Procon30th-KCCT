#pragma once

#include "../interface.hpp"


namespace solver
{
	namespace engine
	{
		namespace controller
		{
			class Controller : public Interface
			{
				Command agentIntentions;

			public:
				void setStage(const simulator::Stage &stage)override
				{

				}
				void think()override
				{
					//�W�����͂ɂ��G�[�W�F���g�̈ӎv�\����agentIntentions�ϐ��ɕۑ�����
				}
				Command getBestActions()const override
				{
					return agentIntentions;
				}
			};
		}
	}
}