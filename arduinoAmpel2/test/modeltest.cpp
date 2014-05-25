

#include <gtest/gtest.h>

#include "TrafficlightRequired.h"
#include "Trafficlight.h"

namespace {


class TrafficlightTest : public ::testing::Test {
 protected:
	Trafficlight handle;
  virtual void SetUp() {
		trafficlight_init(&handle);
		trafficlight_enter(&handle);
  }

  virtual void TearDown() {
	  trafficlight_exit(&handle);
  }
};


TEST_F(TrafficlightTest, InitState){
	EXPECT_TRUE(trafficlight_isActive(&handle, Trafficlight_main_region_off));
}

TEST_F(TrafficlightTest, GotoOnState){
	trafficlightIface_raise_onOff(&handle);
	trafficlight_runCycle(&handle);
	EXPECT_TRUE(trafficlight_isActive(&handle, Trafficlight_main_region_on));

}

}
