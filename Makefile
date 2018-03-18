TARGET=Orbiter
SOURCES=main.cpp GLUTWindow.cpp MapView.cpp FutureTrackRender.cpp VesselView.cpp Orbiter.cpp OrbiteeData.cpp OrbitRender.cpp OpenGL3D.cpp OrbitInfo.cpp BasicVessel.cpp GeneralVessel.cpp
LDFLAGS+=-lGL -lGLU -lglut

run: $(TARGET)
	$(PWD)/$<

all: $(TARGET)

$(TARGET): $(SOURCES:%.cpp=%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

%.h:
	touch $@
