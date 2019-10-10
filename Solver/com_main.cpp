#include<iostream>
#include<string>
#include "Com/com_interface.hpp"
#include<windows.h>

int main()
{
	solver::com::ComInterface comInterFace("3000","6","procon30_example_token");
	solver::com::ReceivedMatchInfo receivedMatchInfo;
	solver::com::ReceivedMatchData receivedMatchData;

	system("chcp 65001"); //コマンドプロンプトの文字コードページをUTF-8に設定

	//試合情報取得
	std::cout << comInterFace.getMatchInfo(&receivedMatchInfo) << std::endl;
	for (solver::com::ReceivedMatchInfoOne receivedMatchInfoOne : receivedMatchInfo.MatchesInfo)
	{
		std::cout << "id : " << receivedMatchInfoOne.id << std::endl;
		std::cout << "intervalMillis : " << receivedMatchInfoOne.intervalMillis << std::endl;
		std::cout << "matchTo : " << receivedMatchInfoOne.matchTo << std::endl;
		std::cout << "teamID : " << receivedMatchInfoOne.teamID << std::endl;
		std::cout << "turnMillis : " << receivedMatchInfoOne.turnMillis << std::endl;
		std::cout << "turns : " << receivedMatchInfoOne.turns << std::endl;
	}
	std::cout << comInterFace.getMatchData(&receivedMatchData) << std::endl;

	//試合データ取得


	//std::cout << receivedMatchInfo.MatchesInfo[0].id << std::endl;
	
	//std::cout << comInterFace.getCmdString() << std::endl;
	//system(comInterFace.getCmdString().c_str());
	//system("curl -H \"Authorization: procon30_example_token\" \"http://localhost:3000/matches\"");
	
	Sleep(3*1000);
	return 0;
}
