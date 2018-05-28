#ifndef XTHREE_LINE_BASIC_MATERIAL_HPP
#define XTHREE_LINE_BASIC_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // line_basic_material declaration
    //

    template<class D>
    class xline_basic_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(double, derived_type, linewidth, 1);
        XPROPERTY(std::string, derived_type, linecap, "round");
        XPROPERTY(std::string, derived_type, linejoin, "round");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xline_basic_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_basic_material = xw::xmaterialize<xline_basic_material>;

    using line_basic_material_generator = xw::xgenerator<xline_basic_material>;

    //
    // line_basic_material implementation
    //


    template <class D>
    inline void xline_basic_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(linewidth, state, buffers);
        xw::set_patch_from_property(linecap, state, buffers);
        xw::set_patch_from_property(linejoin, state, buffers);
    }

    template <class D>
    inline void xline_basic_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(linewidth, patch, buffers);
        xw::set_property_from_patch(linecap, patch, buffers);
        xw::set_property_from_patch(linejoin, patch, buffers);
    }

    template <class D>
    inline xline_basic_material<D>::xline_basic_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_basic_material<D>::set_defaults()
    {
        this->_model_name() = "LineBasicMaterialModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xline_basic_material>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xline_basic_material>;
        extern template xw::xmaterialize<xthree::xline_basic_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xline_basic_material>>;
        extern template class xw::xgenerator<xthree::xline_basic_material>;
        extern template xw::xgenerator<xthree::xline_basic_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xline_basic_material>>;
    #endif
#endif

#endif