#ifndef MAGIC_PET_HPP
#define MAGIC_PET_HPP

#include "Pet.hpp"
#include "SpecialAbility.hpp"

class MagicPet : public Pet, public SpecialAbility {
  public:
    void makeSound() override;
    void doTrick() override;
};

#endif
