#pragma once

#include <opendxa/core/opendxa.h>
#include <opendxa/core/lammps_parser.h>
#include <opendxa/core/particle_property.h>
#include <opendxa/analysis/centrosymmetry.h>
#include <nlohmann/json.hpp>
#include <string>

namespace OpenDXA{
using json = nlohmann::json;

class CentroSymmetryWrapper{
public:
    CentroSymmetryWrapper();

    void setNumNeighbors(int k);
    void setMode(CentroSymmetryAnalysis::CSPMode mode);

    json compute(const LammpsParser::Frame& frame, const std::string& outputBase);

private:
    std::shared_ptr<Particles::ParticleProperty> createPositionProperty(const LammpsParser::Frame& frame);

    int _k;
    CentroSymmetryAnalysis::CSPMode _mode;
};

}
