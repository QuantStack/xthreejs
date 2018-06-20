#ifndef XTHREE_WEBGL_SHADER_HPP
#define XTHREE_WEBGL_SHADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // webgl_shader declaration
    //

    template<class D>
    class xwebgl_shader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xwebgl_shader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_shader = xw::xmaterialize<xwebgl_shader>;

    using webgl_shader_generator = xw::xgenerator<xwebgl_shader>;

    //
    // webgl_shader implementation
    //


    template <class D>
    inline void xwebgl_shader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_shader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_shader<D>::xwebgl_shader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_shader<D>::set_defaults()
    {
        this->_model_name() = "WebGLShaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_shader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xwebgl_shader>;
        extern template xw::xmaterialize<xthree::xwebgl_shader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_shader>>;
        extern template class xw::xgenerator<xthree::xwebgl_shader>;
        extern template xw::xgenerator<xthree::xwebgl_shader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xwebgl_shader>>;
    #endif
#endif

#endif