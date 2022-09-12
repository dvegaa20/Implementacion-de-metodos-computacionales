#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>


template <class T>
void bubbleSortDay(std::vector<T> &v) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].day > v[j + 1].day){
				swap(v, j, j + 1);
			}
		}
	}
}

template <class T>
void bubbleSortMonth(std::vector<T> &v) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].month > v[j + 1].month){
				swap(v, j, j + 1);
			}
		}
	}
}

#endif