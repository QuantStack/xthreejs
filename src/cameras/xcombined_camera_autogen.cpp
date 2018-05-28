#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcombined_camera>;
template xw::xmaterialize<xthree::xcombined_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcombined_camera>>;
template class xw::xgenerator<xthree::xcombined_camera>;
template xw::xgenerator<xthree::xcombined_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcombined_camera>>;