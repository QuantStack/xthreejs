#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwireframe_geometry>;
template xw::xmaterialize<xthree::xwireframe_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwireframe_geometry>>;
template class xw::xgenerator<xthree::xwireframe_geometry>;
template xw::xgenerator<xthree::xwireframe_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwireframe_geometry>>;