#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbuffer_geometry_loader>;
template xw::xmaterialize<xthree::xbuffer_geometry_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_geometry_loader>>;
template class xw::xgenerator<xthree::xbuffer_geometry_loader>;
template xw::xgenerator<xthree::xbuffer_geometry_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbuffer_geometry_loader>>;