#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xvertex_normals_helper>;
template xw::xmaterialize<xthree::xvertex_normals_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xvertex_normals_helper>>;
template class xw::xgenerator<xthree::xvertex_normals_helper>;
template xw::xgenerator<xthree::xvertex_normals_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xvertex_normals_helper>>;