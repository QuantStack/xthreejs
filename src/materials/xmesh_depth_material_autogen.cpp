#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmesh_depth_material>;
template xw::xmaterialize<xthree::xmesh_depth_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmesh_depth_material>>;
template class xw::xgenerator<xthree::xmesh_depth_material>;
template xw::xgenerator<xthree::xmesh_depth_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmesh_depth_material>>;