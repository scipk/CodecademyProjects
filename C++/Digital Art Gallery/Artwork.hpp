#pragma once

#include <string>

class Artwork {
public:
  std::string title;
  std::string artistName;
  int id;
  std::string medium;
  double price;
  bool sold;

  Artwork() = delete;

  Artwork(std::string artTitle = "Untitled", std::string artistFullName = "Unknown", int artworkId = -1, std::string artworkMedium = "N/A", double artworkPrice = 0.0, bool soldStatus = false);

  Artwork(const Artwork& other);

  Artwork(Artwork&& other);

  void markAsSold();
};