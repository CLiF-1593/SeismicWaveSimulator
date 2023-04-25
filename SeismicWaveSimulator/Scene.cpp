#include "Scene.h"
#include <thread>
#include <iostream>
#include <Log.h>
using namespace std;

Scene::Scene(int update_delay){
    Log::PrintDebugLog("Scene", "Constructor", "������ ȣ��");
    this->run = true;
    this->process_completed = false;
    this->update_delay = update_delay;
    thread th([&]() {this->__Process__();});
    th.detach();
}

Scene::~Scene() {
    Log::PrintDebugLog("Scene", "Destructor", "�Ҹ��� ȣ��");
    this->run = false;
    while (!this->process_completed);
    //TODO : Destroy Data
}

int Scene::SetWindow(Window* win) {
    this->win = win;
    return 0;
}

int Scene::PushEvent(Event::Event evt) {
    this->event_queue.push(evt);
    return 0;
}

int Scene::__Process__() {
    while (this->run) {
        while (!this->event_queue.empty()) {
            this->EventProcess(this->event_queue.front());
            this->event_queue.pop();
        }
        this->NormalProcess();
        SDL_Delay(update_delay);
    }
    this->process_completed = true;
    return 0;
}

bool Scene::IsRun() {
    return this->run;
}
