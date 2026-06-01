#include "Gallery.hpp"
#include "Exhibition.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  std::cout << std::fixed << std::setprecision(0);

  Artwork sunflowers("Sunflowers", "Vincent van Gogh", 1, "oil painting", 1200000);

  cout << "ID: " << sunflowers.id << ", Title: " << sunflowers.title << ", Artist: " << sunflowers.artistName << ", Medium: " << sunflowers.medium << ", Price: " << sunflowers.price << endl;

  Artwork starryNight("Starry Night", "Vincent van Gogh", 2, "oil painting", 1000000);

  Artwork galleryCopy(starryNight);
  cout << "ID: " << starryNight.id << ", Title: " << starryNight.title << ", Artist: " << starryNight.artistName << ", Medium: " << starryNight.medium << ", Price: " << starryNight.price << endl;

  Artwork artworkForTransfer = std::move(starryNight);
  cout << "ID: " << artworkForTransfer.id << ", Title: " << artworkForTransfer.title << ", Artist: " << artworkForTransfer.artistName << ", Medium: " << artworkForTransfer.medium << ", Price: " << artworkForTransfer.price << endl;

  Artwork auctionTransfer(artworkForTransfer);
  cout << "ID: " << auctionTransfer.id << ", Title: " << auctionTransfer.title << ", Artist: " << auctionTransfer.artistName << ", Medium: " << auctionTransfer.medium << ", Price: " << auctionTransfer.price << endl;

  Artwork theScream("The Scream", "Edvard Munch", 3, "tempera", 1500000);
  Artwork digitalDream ("Digital Dream", "Alice Doe", 4, "digital art", 5000);

  Gallery gallery;

  gallery.addArtwork(std::move(sunflowers));
  gallery.addArtwork(std::move(theScream));
  gallery.addArtwork(std::move(digitalDream));

  gallery.displayGallery();

  Exhibition exhibition;

  exhibition.addToExhibition(&gallery.artworks[0]);
  exhibition.addToExhibition(&gallery.artworks[2]);

  exhibition.showExhibition();

  gallery.sellArtwork(4);
  exhibition.showExhibition();

  return 0;
}
