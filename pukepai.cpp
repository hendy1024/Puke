#include "pukepai.h"

PuKePai::PuKePai()
{

}
PuKePai::~PuKePai()
{
  
}

void PuKePai::Init()
{
	for(int i = 0; i < MAX_PUKE_NUM; ++i)
	{
		m_puke_list.insert(i);
	}
}

bool PuKePai::XiPai()
{
	if(m_puke_list.empty())
	{
		print("没有扑克牌");
		return false;
	}
  
	std::random_shuffle(m_puke_list.begin(), m_puke_list.end());
	return true;
}

bool PuKePai::FaPai(int *puke_num)
{
	if(m_puke_list.empty())
	{
		print("没有扑克牌");
		return false;
	}
  
	std::iterator iter = m_puke_list.begin();
	*puke_num = iter;
	return true;
}

bool PuKePai::FaPai(int num, std::vector<int> &puke_list)
{
	if(num < 1)
	{
		print("不需要发牌");
		return false;
	}
	if(m_puke_list.empty())
	{
		print("没有扑克牌");
		return false;
	}
	if(num < (int)m_puke_list.size())
	{
		print(牌不够发);
		return false;
	}
  
	std::iterator iter = m_puke_list.begin();
	for(;iter != m_puke_list.end() && num > 0; --num)
	{
		puke_list.insert(iter);
		m_puke_list.earse(iter);
	}
	if((int)puke_list.size() <= 0)
	{
		return false;
	}
	return true;
}

bool PukePai::GetPukePaiRealMean(int puke_index, int *puke_type, int *puke_real_index)
{
	if(puke_index <= 0 || puke_index > MAX_PUKE_NUM)
	{
		return false;
	}

	*puke_type = (puke_idnex / MAX_PUKE_REAL_INDEX) + 1;
	*puke_real_index = puke_idnex - (*puke_type) * MAX_PUKE_REAL_INDEX;
	return true;
}

