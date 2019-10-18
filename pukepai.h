#ifndef PUKE_PAI_H
#define PUKE_PAI_H

#include <set>
class PuKePai
{
public:
	virtual PuKePai();
	virtual ~PuKePai();

public:
	void Init();
	bool XiPai();
	bool FaPai(int *puke_num);	//单张扑克
	bool FaPai(int num, std::vector<int> &puke_list);	//多张扑克
  
	enum PukeType = {
		Spade = 1,
		Heart,
		Diamond,
		Club,
	};

	bool GetPukePaiRealMean(int puke_index, int *puke_type, int *puke_real_index);

private:
	const int MAX_PUKE_NUM = 54;
	const int MAX_PUKE_REAL_INDEX = 13;

	std::set<int> m_puke_list;	
}
