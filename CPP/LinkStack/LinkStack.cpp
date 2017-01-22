/*
* author: acme
*   date: 2017-1-22
*  blogs: http://blog.csdn.net/qq_18297675
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node   //节点类
{
public:
	Node<T>(T d, Node<T>* n = NULL) : data(d), next(n) {}
public:
	T data;
	Node<T>* next;
};

template<typename T>
class LinkStack
{
public:
	LinkStack();
	LinkStack(T initValue);
	~LinkStack();
	
	bool IsEmpty();		//栈是否为空   
	int GetSize();		//获取当前栈的长度	
	void Push(T e);		//入栈			
	void Pop();			//出栈(不返回栈顶元素)				
	T PopE();			//出栈(返回栈顶元素)	
	T GetTop();		//获取栈顶元素					
	void Print();		//遍历栈	
	void ClearStack();  //清空栈
private:
	void InitStack();  //初始化栈
private:
	Node<T>* m_top;    //栈顶指针   
	int m_count;       //记录栈的大小
	T m_initValue;     //节点的初始值，防止string用int来初始化所带来的错误
};

//默认构造函数
template<typename T>
LinkStack<T>::LinkStack()
{
	m_initValue = 0;
	InitStack();  //初始化栈
}

//有参构造
template<typename T>
LinkStack<T>::LinkStack(T initValue)
{
	m_initValue = initValue;
	InitStack();  //初始化栈
}

//默认析构函数
template<typename T>
LinkStack<T>::~LinkStack()
{
	delete m_top;
}

//初始化栈
template<typename T>
void LinkStack<T>::InitStack()
{
	m_top = new Node<T>(m_initValue);   //创建栈顶指针
	m_count = 0;
}

//栈是否为空 
template<typename T>
bool LinkStack<T>::IsEmpty()
{
	return m_count == 0 ? true : false;
}

//获取当前栈的长度
template<typename T>
int LinkStack<T>::GetSize()
{
	return m_count;
}

//入栈
template<typename T>
void LinkStack<T>::Push(T e)
{
	Node<T>* node = new Node<T>(m_initValue);  //创建一个新的节点
	node->data = e;
	node->next = m_top->next;  
	m_top->next = node;          //让栈顶指针指向新的栈顶节点
	++m_count;
}

//出栈(不返回栈顶元素)
template<typename T>
void LinkStack<T>::Pop()
{
	if (IsEmpty())        //如果栈为空，则什么也不做
		cout << "栈为空，出栈操作失败." << endl;
	else
	{
		Node<T>* temp = m_top->next;//保存将要出栈的元素（其实就是链表中删除元素的步骤）
		m_top->next = temp->next;
		--m_count;
		delete temp;    //释放节点
	}
}

//出栈(返回栈顶元素)	
template<typename T>
T LinkStack<T>::PopE()
{
	if (IsEmpty())
		cout << "栈为空，出栈操作失败." << endl;
	else
	{
		Node<T>* temp = m_top->next;//保存将要出栈的元素（其实就是链表中删除元素的步骤）
		T data = temp->data;       //保存要返回的值
		m_top->next = temp->next;
		--m_count;
		delete temp;    //释放节点
		return data;
	}
}

//获取栈顶元素	
template<typename T>
T LinkStack<T>::GetTop()
{
	return !IsEmpty()? m_top->next->data : m_initValue; //不空才能返回数据
}

//遍历栈	
template<typename T>
void LinkStack<T>::Print()
{
	if (IsEmpty())
		cout << "栈为空，遍历栈操作失败." << endl;
	else
	{
		Node<T>* cur = m_top;    //和链表遍历一样
		while (cur = cur->next)  
			cout << cur->data << endl;
	}
}

//清空栈
template<typename T>
void LinkStack<T>::ClearStack()
{
	if (IsEmpty())
		cout << "栈为空，清空栈操作失败." << endl;
	else
	{
		while (m_count)
			Pop();
		m_top->next = NULL;
	}
}
