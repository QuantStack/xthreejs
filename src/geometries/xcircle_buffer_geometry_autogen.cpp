#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcircle_buffer_geometry>;
template xw::xmaterialize<xthree::xcircle_buffer_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcircle_buffer_geometry>>;
template class xw::xgenerator<xthree::xcircle_buffer_geometry>;
template xw::xgenerator<xthree::xcircle_buffer_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcircle_buffer_geometry>>;