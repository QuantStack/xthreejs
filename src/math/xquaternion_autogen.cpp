#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xquaternion>;
template xw::xmaterialize<xthree::xquaternion>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xquaternion>>;
template class xw::xgenerator<xthree::xquaternion>;
template xw::xgenerator<xthree::xquaternion>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xquaternion>>;