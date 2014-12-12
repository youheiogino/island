#define SKETCH_2D_IMPLEMENTATION
#include "sketch2d.h"

const char sentence[] = "Hello world, Island C API is cool!";
PAudio speech;
PFont font;

void setup()
{
    speech = loadSpeech(sentence);
    playAudio(speech);

    font = loadFont("../3rdparty/nanovg/example/Roboto-Regular.ttf");
}

void draw()
{
    background(gray(122));
    if (Soloud_getActiveVoiceCount(soloud) > 0)
    {
        float * v = Soloud_calcFFT(soloud);
        int p = (int)(v[10] * 30);
		rect(10, 10, p * 10, 30);
    }

    textFont(font);
    textAlign(NVG_ALIGN_LEFT);
    textSize(30);
    textLeading(5);
	text(sentence, 10, 100);
}

void shutdown()
{
    destroyAudio(speech);
}
