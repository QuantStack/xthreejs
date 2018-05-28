#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmesh_standard_material>;
template xw::xmaterialize<xthree::xmesh_standard_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmesh_standard_material>>;
template class xw::xgenerator<xthree::xmesh_standard_material>;
template xw::xgenerator<xthree::xmesh_standard_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmesh_standard_material>>;