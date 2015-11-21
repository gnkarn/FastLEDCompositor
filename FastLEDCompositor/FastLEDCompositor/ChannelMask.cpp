// 
// 
// 

#include "ChannelMask.h"
#include "disco.h"
ChannelMask::ChannelMask() {}
ChannelMask::~ChannelMask() {}

void ChannelMask::setDuration(long duration) {
	this->duration = duration;
	this->endtime = this->starttime + duration;
}
void ChannelMask::setStartTime(long mytime) {
	this->starttime = mytime;
}


boolean ChannelMask::isOver() {
	if (millis()>=endtime) {
		return true;
	}
	else {
		return false;
	}
	
}

uint8_t ChannelMask::getValInt(boolean direction) {
	long temp;
	if (millis() - starttime > duration) { return 0; }
	if (direction) {
		temp = endtime - millis();
	}
	else {
		temp = (millis() - starttime);
	}
	temp = temp * 256 / duration;
	if (direction) {
		temp = map8(temp, 0, startPercent);
	}
	return temp;
}

void ChannelMask::setPercent(uint8_t percent) {
	startPercent = percent;
}