#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xorthographic_camera>;
template xw::xmaterialize<xthree::xorthographic_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xorthographic_camera>>;
template class xw::xgenerator<xthree::xorthographic_camera>;
template xw::xgenerator<xthree::xorthographic_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xorthographic_camera>>;