#ifndef XTHREE_WEBGL_CAPABILITIES_HPP
#define XTHREE_WEBGL_CAPABILITIES_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_capabilities declaration
    //

    template<class D>
    class xwebgl_capabilities : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xwebgl_capabilities();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_capabilities = xw::xmaterialize<xwebgl_capabilities>;

    using webgl_capabilities_generator = xw::xgenerator<xwebgl_capabilities>;

    //
    // webgl_capabilities implementation
    //

    template <class D>
    inline void xwebgl_capabilities<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_capabilities<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_capabilities<D>::xwebgl_capabilities()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_capabilities<D>::set_defaults()
    {
        this->_model_name() = "WebGLCapabilitiesModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_capabilities));
//}
#endif