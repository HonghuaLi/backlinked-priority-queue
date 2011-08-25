/*
 *  backlinked priority queue
 *  Copyright (c) 2011
 *      Honghua (Howard) Li <howard.hhli@gmail.com>
 *      Oliver van Kaick <ovankaic@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details (file COPYING).
 */

#ifndef _BACKLINKED_PRIORITY_QUEQUE_
#define _BACKLINKED_PRIORITY_QUEQUE_

#include <vector>
using namespace std;
typedef double pq_key_t;
typedef void* pq_data_t;
typedef int pq_index_t;
		

// record
class pq_record
{
public:
	pq_record(pq_key_t key, pq_data_t data, pq_index_t* id_backlink)
		:key(key), data(data),index_backlink(id_backlink){}

	pq_key_t key;
	pq_data_t data;
	pq_index_t* index_backlink;
};


// Priority queue ordering 
enum pq_order_t{
	pq_max = 0,
	pq_min = 1,
};




//backlinked priority queue
class backlinked_priority_queue
{
	vector<pq_record> records;

	bool compare_record(pq_index_t id1, pq_index_t id2);
	void swap_record(pq_index_t id1, pq_index_t id2);

	void fix_up(pq_index_t index);
	void fix_down(pq_index_t index);

public:
	backlinked_priority_queue(pq_order_t order);
	~backlinked_priority_queue();

	pq_order_t pq_order;

	bool empty();
	size_t size();

	pq_record top_rec();
	pq_data_t top();
	void push_rec(pq_record &rec);
	void push(pq_key_t key, pq_data_t data, pq_index_t *index_backlink);
	pq_record pop_rec();
	pq_data_t pop();
	pq_record erase_rec(int index);	
	pq_data_t erase(int index);
};


#endif /*_BACKLINKED_PRIORITY_QUEQUE_*/
