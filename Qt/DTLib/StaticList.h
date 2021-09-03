#ifndef STATICLIST_H
#define STATICLIST_H


#include "SeqList.h"



namespace DTLib
{


template <typename T,int N>
class StaticList:public SeqList<T>
{
protected:
    T m_space[N];                //顺序存储空间， N为模板参数,但不代表填入数据元素个数，只代表顺序存储线性表结构的大小
public:
    StaticList()                 //指定父类成员的具体值
    {
        this->m_array = m_space;
        this->m_length = 0;
    }


    int capacity() const
    {
        return N;
    }
};





}


#endif // STATICLIST_H
