#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_mixer>;
template xw::xmaterialize<xthree::xanimation_mixer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_mixer>>;
template class xw::xgenerator<xthree::xanimation_mixer>;
template xw::xgenerator<xthree::xanimation_mixer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_mixer>>;