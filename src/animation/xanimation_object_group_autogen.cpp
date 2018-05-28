#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_object_group>;
template xw::xmaterialize<xthree::xanimation_object_group>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_object_group>>;
template class xw::xgenerator<xthree::xanimation_object_group>;
template xw::xgenerator<xthree::xanimation_object_group>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_object_group>>;