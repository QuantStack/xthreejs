#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdodecahedron_geometry>;
template xw::xmaterialize<xthree::xdodecahedron_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdodecahedron_geometry>>;
template class xw::xgenerator<xthree::xdodecahedron_geometry>;
template xw::xgenerator<xthree::xdodecahedron_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdodecahedron_geometry>>;