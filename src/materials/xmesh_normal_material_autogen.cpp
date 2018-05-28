#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmesh_normal_material>;
template xw::xmaterialize<xthree::xmesh_normal_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmesh_normal_material>>;
template class xw::xgenerator<xthree::xmesh_normal_material>;
template xw::xgenerator<xthree::xmesh_normal_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmesh_normal_material>>;