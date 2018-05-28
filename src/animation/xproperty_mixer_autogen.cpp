#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xproperty_mixer>;
template xw::xmaterialize<xthree::xproperty_mixer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xproperty_mixer>>;
template class xw::xgenerator<xthree::xproperty_mixer>;
template xw::xgenerator<xthree::xproperty_mixer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xproperty_mixer>>;