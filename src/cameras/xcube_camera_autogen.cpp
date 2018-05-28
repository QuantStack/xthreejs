#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcube_camera>;
template xw::xmaterialize<xthree::xcube_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcube_camera>>;
template class xw::xgenerator<xthree::xcube_camera>;
template xw::xgenerator<xthree::xcube_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcube_camera>>;