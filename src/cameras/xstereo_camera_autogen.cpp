#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xstereo_camera>;
template xw::xmaterialize<xthree::xstereo_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xstereo_camera>>;
template class xw::xgenerator<xthree::xstereo_camera>;
template xw::xgenerator<xthree::xstereo_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xstereo_camera>>;