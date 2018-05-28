#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::ximmediate_render_object>;
template xw::xmaterialize<xthree::ximmediate_render_object>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::ximmediate_render_object>>;
template class xw::xgenerator<xthree::ximmediate_render_object>;
template xw::xgenerator<xthree::ximmediate_render_object>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::ximmediate_render_object>>;