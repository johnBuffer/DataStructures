#pragma once
#include <memory>

// Sugar types
template<typename T>
class BinaryTreeNode;

template<typename T>
using BinaryTreeNodePtr = std::shared_ptr<BinaryTreeNode<T>>;

// Represents tree's nodes
template<typename T>
class BinaryTreeNode
{
public:
	BinaryTreeNode() :
		m_val(),
		m_sub_left(nullptr),
		m_sub_right(nullptr)
	{}

	BinaryTreeNode(const T& val) :
		m_val(val),
		m_sub_left(nullptr),
		m_sub_right(nullptr)
	{}

	void setLeftSub(T& val)
	{
		m_sub_left = std::make_shared<BinaryTreeNode>(val);
	}

	void setRightSub(T& val)
	{
		m_sub_right = std::make_shared<BinaryTreeNode>(val);
	}

	const BinaryTreeNodePtr left() const
	{
		return m_sub_left;
	}

	const BinaryTreeNodePtr right() const
	{
		return m_sub_right;
	}

private:
	T m_val;
	BinaryTreeNodePtr<T> m_sub_left;
	BinaryTreeNodePtr<T> m_sub_right;
};


// The tree structure
template<typename T>
class BinaryTree
{
public:
	BinaryTree() :
		m_root(nullptr)
	{}

	virtual void add(const T& val) = 0;

	const BinaryTreeNodePtr<T> root() const
	{
		return m_root;
	}

private:
	BinaryTreeNodePtr<T> m_root;
};