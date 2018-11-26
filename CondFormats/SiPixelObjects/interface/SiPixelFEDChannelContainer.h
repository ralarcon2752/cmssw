#ifndef CondFormats_SiPixelObjects_SiPixelFEDChannelContainer_h 
#define CondFormats_SiPixelObjects_SiPixelFEDChannelContainer_h

#include "CondFormats/SiPixelObjects/interface/SiPixelQuality.h"
#include "CondFormats/Serialization/interface/Serializable.h"
#include "DataFormats/SiPixelDetId/interface/PixelFEDChannel.h"   // N.B. a DataFormat is serialized here (need for dedicated serialization rules, see CondFormats/External/interface/PixelFEDChannel.h)

#include <map>
#include <string>
#include <vector>

class SiPixelFEDChannelContainer{
public:
  typedef std::map<DetId,std::vector<PixelFEDChannel> > SiPixelFEDChannelCollection;
  typedef std::unordered_map<std::string, SiPixelFEDChannelCollection> SiPixelBadFEDChannelsScenarioMap;
  
  SiPixelFEDChannelContainer(){}
  virtual ~SiPixelFEDChannelContainer(){}

  void setScenario(const std::string &theScenarioId, const SiPixelFEDChannelCollection &theBadFEDChannels);
  void setScenario(const std::string &theScenarioId, const SiPixelQuality &theSiPixelQuality, const SiPixelFedCablingMap& theFedCabling);
                  
  const SiPixelBadFEDChannelsScenarioMap& getScenarioMap () const  {return m_scenarioMap;}

  SiPixelFEDChannelCollection   getSiPixelBadFedChannels(const std::string &ScenarioId) const;
  SiPixelFEDChannelCollection & getSiPixelBadFedChannels(const std::string &ScenarioId);

  std::vector<PixelFEDChannel>& getSiPixelBadFedChannelsInDetId(const std::string &theScenarioId,DetId theDetId);

  std::unique_ptr<PixelFEDChannelCollection> getDetSetBadPixelFedChannels(const std::string &ScenarioId) const;
  
  double size()const {return m_scenarioMap.size();}
  std::vector<std::string> getScenarioList() const;

  void printAll() const;

private:

  SiPixelBadFEDChannelsScenarioMap m_scenarioMap;

  COND_SERIALIZABLE;

};

#endif
