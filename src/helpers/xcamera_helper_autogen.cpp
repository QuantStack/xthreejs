#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcamera_helper>;
template xw::xmaterialize<xthree::xcamera_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcamera_helper>>;
template class xw::xgenerator<xthree::xcamera_helper>;
template xw::xgenerator<xthree::xcamera_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcamera_helper>>;