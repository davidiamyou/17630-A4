//
//  node.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include "node.hpp"

Node::Node(Data* data)
{
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

Node* Node::getPrev()
{
    return this->prev;
}

Node* Node::getNext()
{
    return this->next;
}

bool Node::hasPrev()
{
    return this->prev != NULL;
}

bool Node::hasNext()
{
    return this->next != NULL;
}

Data* Node::getData()
{
    return this->data;
}

// Here we abstract some of the next,prev pointer setting in chaining
// so the job by linked list would be easier
void Node::setNext(Node *newNode)
{
    if (this->hasNext())
    {
        this->getNext()->prev = NULL;
    }
    this->next = newNode;
    if (this->hasNext() && this->getNext()->getPrev() != this)
    {
        this->getNext()->setPrev(this);
    }
}

// Here we abstract some of the next,prev pointer setting in chaining
// so the job by linked list would be easier
void Node::setPrev(Node *newNode)
{
    if (this->hasPrev())
    {
        this->getPrev()->next = NULL;
    }
    this->prev = newNode;
    if (this->hasPrev() && this->getPrev()->getNext() != this)
    {
        this->getPrev()->setNext(this);
    }
}

void Node::setData(Data *newData)
{
    this->data = newData;
}

int Node::compare(Node *other)
{
    return this->getData()->compare(other->getData());
}

Node::~Node()
{
    this->prev = NULL;
    this->next = NULL;
    delete this;
}
