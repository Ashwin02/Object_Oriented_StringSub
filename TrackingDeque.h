/*
 * TrackingDeque.h
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */

#ifndef TRACKINGDEQUE_H_
#define TRACKINGDEQUE_H_

#include<deque>
#include<iostream>

using namespace std;

template <typename D>
class TrackingDeque : public deque<D>
{
  public:
      TrackingDeque();
      ~TrackingDeque();
      void push_back(const D& element);
      void push_front(const D& element);

  private:
      int max_size;

};

template <typename D>
TrackingDeque<D>::TrackingDeque() : max_size(0)
{
}

template <typename D>
TrackingDeque<D>::~TrackingDeque()
{
  cout<<"--->  " << max_size << "  <---" << endl;
}

template <typename D>
void TrackingDeque<D>::push_back(const D& element)
{
  deque<D>::push_back(element);
  if(deque<D>::size() > max_size)
  {
    max_size = deque<D>::size();
  }
}

template <typename D>
void TrackingDeque<D>::push_front(const D& element)
{
  deque<D>::push_front(element);
  if(deque<D>::size() > max_size)
  {
    max_size = deque<D>::size();
  }
}




#endif /* TRACKINGDEQUE_H_ */
