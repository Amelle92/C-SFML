/*
  Copyright 2015 Adam Melle
  
  based on Fred Martin's GuitarHeroLite.cpp

  based on Princeton's GuitarHeroLite.java
  www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/guitar.html
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "GuitarString.hpp"

#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamplesFromString(GuitarString gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;

  // Vector of all the sample vectors
  std::vector <std::vector <sf::Int16> > allsamples;

  // Vector of 37 SoundBuffers
  std::vector <sf::SoundBuffer> SoundBuffers;

  // Vector of 37 Sounds
  std::vector <sf::Sound> Sounds;

  // Fill allsamples with 37 samples
  for (int x = 0; x < 37; x++) {
      std::vector<sf::Int16> samples;
      samples = makeSamplesFromString(GuitarString(440 *
                                     (pow(2, ((x-24)/12)))));
      allsamples.push_back(samples);
  }

  // Fill SoundBuffers with each SoundBuffer
  for (int x = 0; x < 37; x++) {
      sf::SoundBuffer buffer;
      if (!buffer.loadFromSamples(&allsamples[x][0],
          allsamples[x].size(), 2, SAMPLES_PER_SEC))
          throw std::runtime_error("sf::SoundBuffer: failed to "
                                   "load from samples.");

      SoundBuffers.push_back(buffer);
  }

  // Fill Sounds with all sound objects each conatining a SoundBuffer
  for (int x = 0; x < 37; x++) {
      sf::Sound sound;
      sound.setBuffer(SoundBuffers[x]);
      Sounds.push_back(sound);
  }

  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  unsigned int i;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
       case sf::Event::Closed:
        window.close();
        break;

       case sf::Event::TextEntered:
        i = keyboard.find(event.text.unicode);
        if (i < 37)
          Sounds[i].play();
        break;
       default:
      break;
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}
