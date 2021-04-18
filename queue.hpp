#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  T priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> qBaru;
  qBaru.head = nullptr;
  qBaru.tail = nullptr;
  return qBaru;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> elementBaru = new Element<T>;
  elementBaru->data = value;
  elementBaru->priority = priority;
  elementBaru->next = nullptr;

  if(q.head == nullptr){
    q.head = elementBaru;
    q.tail = elementBaru;
  }else{
    ElementPtr<T> pHelp = q.head;
    ElementPtr<T> pHelp_2 = nullptr;
    while(pHelp->priority >= priority && pHelp->next != nullptr){
      pHelp_2 = pHelp;
      pHelp = pHelp->next;
    }
    if(pHelp == q.head && pHelp->priority < priority){
      elementBaru->next = pHelp;
      q.head = elementBaru;
    }else if(pHelp == q.tail && pHelp->priority > priority){
      pHelp->next = elementBaru;
      q.tail = elementBaru;
    }else{
      pHelp_2->next = elementBaru;
      elementBaru->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> deleteEl;
  if(q.head == nullptr && q.tail == nullptr){
    deleteEl = nullptr;
  }else if(q.head->next == nullptr){
    deleteEl = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else{
    deleteEl = q.head;
    q.head = q.head->next;
    deleteEl -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat